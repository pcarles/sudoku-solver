#!/usr/bin/python3.5
# -*- coding: utf-8 -*-
"""
interfaceGrille.py
Rôle: générer la grille en fonction d'un string
Auteur: ELVIRA
"""
#----Modules----

from tkinter import *
from bin.solvermodule import *

#----Fonctions----

def displayGrid(grid):
    """
    displayGrid(grid):
    ======================
    Affiche les chiffres sur la grille en fonction de la grille

    @param grid: la grille à prendre
    @type grid: list
    """
    for i in range(9):
                for j in range(9):
                        canvas.create_image(4 + 35*i + 2*(i//3), 4 + 35*j + 2*(j//3), anchor = NW, image=numbersList[grid[i][j]])
                        canvas.pack()

#----Variables globales----

#----Programme principal----

root = Tk()

result = ft_solve("8.6.73..1.1.8....2.4.2...7.5......1...75.13...6......5.5...2.4.2....8.9.3..65.8..")

grid = PhotoImage(file="img/grid/grid.png")

numbersList = 10 * [0]
for i in range(10):
        numbersList[i] = PhotoImage(file="img/numbers/"+str(i)+".png")

canvas = Canvas(root, bg="white", height=320, width=320)

canvas.pack()

displayGrid(result)
root.mainloop()

