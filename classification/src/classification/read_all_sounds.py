#Import libraries
import numpy as np
# pip install playsound
import pygame

def play_sounds():
    pygame.init()
    sound_categories = ['helicopter'] #, 'chainsaw', 'fire', 'handsaw', 'helicopter']
    for category in sound_categories:
        for i in range(40):
            sound_file = f"datasets/soundfiles/{category}_{i}.wav"
            print(f"Playing {sound_file}")
            
            pygame.mixer.music.load(sound_file)
            pygame.mixer.music.play()
            
            while pygame.mixer.music.get_busy():
                pygame.time.Clock().tick(10)  # Adjust the tick rate as needed

play_sounds()


