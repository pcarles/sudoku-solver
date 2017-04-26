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

def enterNumber(pos, result):
   number = StringVar()
   entry = Entry(root, textvariable=number, width=5).pack(side=LEFT, padx=5, pady=5)
   validate = Button(root, text="valider")
   validate.bind('<Return>', putNumber(str(number), pos, result))
   validate.pack()

def putNumber(number, pos, result):
   result[pos] = number
   pos += 1
   print(result)

#----Variables globales----

#----Programme principal----

root = Tk()

numbers = 81 * [0]

canvas = Canvas(root, bg="white", height=320, width=320)
canvas.pack(side=TOP, padx=5, pady = 5)
enterNumber(0, numbers)

root.mainloop()

