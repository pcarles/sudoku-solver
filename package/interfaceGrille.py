#!/usr/bin/python3.5
# -*- coding: utf-8 -*-
"""
interfaceGrille.py
Rôle: générer la grille en fonction d'un string
Auteur: ELVIRA
"""
#----Modules----

from tkinter import *

#----Fonctions----

def afficher_nombre(grid):
    """
    afficher_nombre(grid):
    ======================
    Affiche les chiffres sur la grille en fonction de la grille

    @param grid: la grille à prendre
    @type grid: str
    """
    for i in range(9):
                for j in range(9):
                        canvas.create_image(4 + 35*i + 2*(i//3), 4 + 35*j + 2*(j//3), anchor = NW, image=images[grid[i][j]])
                        canvas.pack()

#----Variables globales----

grid = "img/grid/grid.png"

#----Programme principal----

fenetre = Tk()

grid = ft_solve("1..........3.....7...4................7........3..9..............................")

grille = PhotoImage(file=grid)
images = [0]
for i in range(1, 10):
        images.append(PhotoImage(file=str(i)+".png"))


canvas = Canvas(fenetre, bg="white", height=320, width=320)



ligne = 2
colone = 2
while colone <= 216:
	while ligne <= 216:
		canvas.create_image(ligne, colone, anchor=NW, image=grille)
		ligne = ligne + 107
	colone = colone + 107
	ligne = 2

canvas.pack()
afficher_nombre(grid)
fenetre.mainloop()
