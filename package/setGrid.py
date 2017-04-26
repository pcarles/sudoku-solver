#!/usr/bin/python3.5
# -*- coding: utf-8 -*-
"""
interfaceGrille.py
Rôle: générer la grille en fonction d'un string
Auteur:
"""
#----Modules----

from tkinter import *

#----Fonctions----

def putNumber():
   result[pos] = number.get()
   print(result)

#----Variables globales----

#----Programme principal----

root = Tk()
pos = 0
number = StringVar()
result = 81 * [0]

canvas = Canvas(root, bg="white", height=320, width=320)
canvas.pack(side=TOP, padx=5, pady = 5)

entry = Entry(root, textvariable=number, width=5).pack(side=LEFT, padx=5, pady=5)

validate = Button(root, text="valider", command=putNumber).pack()

root.mainloop()

