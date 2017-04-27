#!/usr/bin/python3.5
# -*- coding: utf-8 -*-
"""
menu.py
Rôle: Créer un menu pour le solveur de sudoku
NomAuteur:
"""

#----Modules----

from tkinter import *
from winsound import *
import os
import doctest

#----Fonctions----

def QuitterLeSolveur():
    """
    Quitter():
    ==========
    Joue un son lorsque l'utilisateur clique sur le bouton "Quitter"
    @param: none
    """
    QuitSound()
    fenetre.destroy()

def ResoudreUnSudoku():
    """
    ResoudreUnSudoku():
    ===================
    Joue un son et appelle un autre script qui lance l'interface de la grille
    @param: none
    """
    QuitSound()

    return 0

#----Variables globales----

Quitter = "img/menu/button/ppm/button_Quitter_State1.ppm"
Resoudre = "img/menu/button/ppm/button_ResoudreUnSudoku_State1.ppm"
BG = "img/menu/background/png/background.png"
Sound = "sound/quit.wav"
Music = "sound/music.wav"
Script = "interfaceGrille.py"

#----Programme principal----

fenetre = Tk()

PlayMusic = lambda: PlaySound(Music, SND_ASYNC)
QuitSound = lambda: PlaySound(Sound, SND_FILENAME)

BoutonQuitter = PhotoImage(file=Quitter)
BoutonResoudre = PhotoImage(file=Resoudre)
BackgroundUI = PhotoImage(file=BG)

canvas = Canvas(fenetre, bg = "white", height=450, width=450)
background_label = Label(fenetre, image=BackgroundUI)
background_label.place(x=0, y=0, relwidth=1, relheight=1)


boutonQuitter = Button(fenetre, image = BoutonQuitter, bd=0, command = QuitterLeSolveur)
boutonResoudre = Button(fenetre, image = BoutonResoudre, bd=0, command = ResoudreUnSudoku)

canvas.pack()
boutonResoudre.pack()
boutonQuitter.pack(pady=1)

PlayMusic()

fenetre.mainloop()

if __name__ == "__main__":
	doctest.testmod()
