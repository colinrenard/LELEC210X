import pickle
from pathlib import Path
from typing import Optional
import numpy as np
import click

import common
from common.logging import logger
from auth import PRINT_PREFIX

from .utils import payload_to_melvecs
import matplotlib.pyplot as plt

N_MELVECS = 20
MELVEC_LENGTH = 20

def plot_specgram(
    specgram,
    ax,
    is_mel=False,
    title=None,
    xlabel="Time index",
    ylabel="Frequency [Hz]",
    cmap="jet",
    cb=True,
    tf=None,
    invert=True,
):
    """Plot a spectrogram (2D matrix) in a chosen axis of a figure.
    Inputs:
        - specgram = spectrogram (2D array)
        - ax       = current axis in figure
        - title
        - xlabel
        - ylabel
        - cmap
        - cb       = show colorbar if True
        - tf       = final time in xaxis of specgram
    """

    if tf is None:
        tf = specgram.shape[1]

    if is_mel:
        ylabel = "Frequency [Mel]"
        im = ax.imshow(
            specgram, cmap=cmap, aspect="auto", extent=[0, tf, specgram.shape[0], 0]
        )
    else:
        im = ax.imshow(
            specgram,
            cmap=cmap,
            aspect="auto",
            extent=[0, tf, int(specgram.size / tf), 0],
        )
    if invert:
        ax.invert_yaxis()

    fig = plt.gcf()
    if cb:
        fig.colorbar(im, ax=ax)

    ax.set_xlabel(xlabel)
    ax.set_ylabel(ylabel)
    ax.set_title(title)
    return None




@click.command()
@click.option(
    "-i",
    "--input",
    "_input",
    default="-",
    type=click.File("r"),
    help="Where to read the input stream. Default to '-', a.k.a. stdin.",
)
@click.option(
    "-m",
    "--model",
    default=None,
    type=click.Path(exists=True, dir_okay=False, path_type=Path),
    help="Path to the trained classification model.",
)
@common.click.melvec_length
@common.click.n_melvecs
@common.click.verbosity
def main(
    _input: Optional[click.File],
    model: Optional[Path],
    melvec_length: int,
    n_melvecs: int,
) -> None:
    """
    Extract Mel vectors from payloads and perform classification on them.
    Classify MELVECs contained in payloads (from packets).

    Most likely, you want to pipe this script after running authentification
    on the packets:

        poetry run auth | poetry run classify

    This way, you will directly receive the authentified packets from STDIN
    (standard input, i.e., the terminal).
    """
    if model:
        with open(model, "rb") as file:
            m = pickle.load(file)
            #m = pickle.load("classification/data/models/randomforest_1000.pickle")
            # poetry run auth | poetry run classify --model path_to_model (use tab)
    else:
        m = None

    CODE_DJ = True
    #m = pickle.load(open("classification/data/models/randomforest_1000.pickle","rb"))

    msg_counter = 0
    cpt = 0
    pred_array = []
    prob_array = []

    for payload in _input:
        if PRINT_PREFIX in payload:
            payload = payload[len(PRINT_PREFIX) :]

            melvecs = payload_to_melvecs(payload, melvec_length, n_melvecs)
            #logger.info(f"Parsed payload into Mel vectors: {melvecs}")

            print(m)

            if m:
                # TODO: perform classification
                fv = melvecs
                fv = fv.reshape(1,400)

                if CODE_DJ:
    
                        msg_counter += 1
                        print("MEL Spectrogram #{}".format(msg_counter))
                        f, ax = plt.subplots(1, 1, figsize=(10, 5))
                        plot_specgram(
                            fv.reshape((N_MELVECS, MELVEC_LENGTH)),
                            ax,
                            is_mel=True,
                            title="MEL Spectrogram #{}".format(cpt),
                        )
                        np.save("Melvecs/%d.npy"%cpt,fv)
                        plt.savefig("Figure/%d.pdf"%cpt)
                        cpt +=1
                        """if cpt <= 40:
                            np.save("Melvecs/birds/n%d.npy"%cpt,fv)
                            plt.savefig("Figure/birds/%d.pdf"%cpt)
                        elif cpt <= 80:
                            np.save("Melvecs/chainsaw/n%d.npy"%(cpt),fv)
                            plt.savefig("Figure/chainsaw/%d.pdf"%(cpt))
                        elif cpt <= 120:
                            np.save("Melvecs/fire/n%d.npy"%(cpt),fv)
                            plt.savefig("Figure/fire/%d.pdf"%(cpt))
                        elif cpt <= 160:
                            np.save("Melvecs/handsaw/n%d.npy"%(cpt),fv)
                            plt.savefig("Figure/handsaw/%d.pdf"%(cpt-120))
                        else:
                            np.save("Melvecs/helicopter/n%d.npy"%(cpt-160),fv)
                            plt.savefig("Figure/helicopter/%d.pdf"%(cpt-160))

                        prediction = m.predict(fv)
                        probas = m.predict_proba(fv)
                        pred_array.append(prediction[0])
                        prob_array.append(probas)
                        cpt+=1
                        print("Predicted class : ", prediction[0])
                        print(probas)
                        if cpt == 40:
                            with open("Predictions proba/test_birds_probs.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in prob_array:
                                    file.write(f"{item}\n")
                            prob_array = []

                            with open("Predictions/test_birds.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in pred_array:
                                    file.write(f"{item}\n")
                            pred_array = []
                        elif cpt == 80:
                            with open("Predictions/test_chainsaw.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in pred_array:
                                    file.write(f"{item}\n")
                            pred_array = []

                            with open("Predictions proba/test_chainsaw_probs.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in prob_array:
                                    file.write(f"{item}\n")
                            prob_array = []
                        elif cpt == 120:
                            with open("Predictions/test_fire.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in pred_array:
                                    file.write(f"{item}\n")
                            pred_array = []

                            with open("Predictions proba/test_fire_probs.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in prob_array:
                                    file.write(f"{item}\n")
                            prob_array = []
                        if cpt == 160:
                            with open("Predictions/test_handsaw.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in pred_array:
                                    file.write(f"{item}\n")
                            pred_array = []

                            with open("Predictions proba/test_handsaw_probs.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in prob_array:
                                    file.write(f"{item}\n")
                            prob_array = []
                        elif cpt == 200:
                            with open("Predictions/test_helicopter.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in pred_array:
                                    file.write(f"{item}\n")
                            pred_array = []

                            with open("Predictions proba/test_helicopter_probs.txt", "w") as file:
                                # Iterate through the list and write each element to the file
                                for item in prob_array:
                                    file.write(f"{item}\n")
                            prob_array = []
                    """
                else:
                    #print(fv.shape)
                    prediction = m.predict(fv)
                    probas = m.predict_proba(fv)
                    print(probas)
                    print(prediction[0])
                    f, ax = plt.subplots(1, 1, figsize=(10, 5))
                    plot_specgram(
                        fv.reshape((20, 20)),
                        ax,
                        is_mel=True,
                        title="MEL Spectrogram"
                    )
                    plt.pause(1)
                    plt.clf()
                    pass
