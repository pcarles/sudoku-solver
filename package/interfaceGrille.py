#!/usr/bin/env python3.5.2
# -*- coding: utf-8 -*-
from tkinter import *

fenetre = Tk()

grid = ft_solve(".................................................................................")

grille = PhotoImage(file="grid.png")
images = [0]
for i in range(1, 10):
        images.append(PhotoImage(file=str(i)+".png"))
	
 
canvas = Canvas(fenetre, bg="white", height=320, width=320)

def afficher_nombre(grid):
        for i in range(9):
                for j in range(9):
                        canvas.create_image(4 + 35*i + 2*(i//3), 4 + 35*j + 2*(j//3), anchor = NW, image=images[grid[i][j]])
                        canvas.pack()

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
        




