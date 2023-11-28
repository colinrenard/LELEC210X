import matplotlib.pyplot as plt
import numpy as np

SNR = np.array([6.03,7.10,7.49,8.17,10.31,10.49,11.06,11.42,12.60,12.66,13.64,14.57,19.69,23.11])
N_err = np.array([0,2,0,1,0,2,4,4,4,4,3,5,5,5])/5.0


plt.grid(zorder=-1.0)
plt.scatter(SNR,N_err*100)

plt.xlabel(r'SNR [dB]')
plt.ylabel(r'Correctly transmitted paquet [%]')
plt.title(r'Packets transmission w.r.t. to the SNR')
plt.show()