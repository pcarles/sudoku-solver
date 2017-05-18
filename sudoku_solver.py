#!/usr/bin/python3.5
# -*- coding: utf-8 -*-

import tkinter as tk
import package.bin.solvermodule as sm

class SudokuSolver(tk.Tk):
    def __init__(self):
        tk.Tk.__init__(self)

        self.title("Sudoku extermivator V1")

        self.bgImg = tk.PhotoImage(file="package/img/background.png")
        self.gridbgImg = tk.PhotoImage(file="package/img/gridbg.png")
        self.quitButtonImg = tk.PhotoImage(file="package/img/quit_button.png")
        self.solveButtonImg = tk.PhotoImage(file="package/img/solve_button.png")
        self.numbersImg = self.loadNumbersImg()

        self.numberGrid = []
        for i in range(9):
            self.numberGrid.append([0] * 9)

        container = tk.Frame(self)
        container.pack(side="top", fill="both", expand=True)

        self.frames = {}

        self.frames["Menu"] = Menu(parent=container, controller=self)
        self.frames["SetGrid"] = SetGrid(parent=container, controller=self)
        self.frames["DisplayGrid"] = DisplayGrid(parent=container, controller=self)

        self.frames["Menu"].grid(row=0, column=0, sticky="nsew")
        self.frames["SetGrid"].grid(row=0, column=0, sticky="nsew")
        self.frames["DisplayGrid"].grid(row=0, column=0, sticky="nsew")

        self.showFrame("Menu")

    def loadNumbersImg(self):
        numberList = 10 * [0]
        for i in range(10):
            numberList[i] = tk.PhotoImage(file="package/img/"+str(i)+".png")

        return numberList

    def displayGrid(self, canvas):
        for i in range(9):
            for j in range(9):
                canvas.create_image(35 * i, 35 * j, anchor="nw", image=self.numbersImg[self.numberGrid[i][j]])

    def showFrame(self, page_name):
        frame = self.frames[page_name]
        frame.tkraise()

class Menu(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.controller = controller

        self.canvas = tk.Canvas(self, bg="white", height=320, width=320)
        self.background = tk.Label(self, image=self.controller.bgImg)
        self.quitButton = tk.Button(self, image=self.controller.quitButtonImg, command=self.quit)
        self.solveButton = tk.Button(self, image=self.controller.solveButtonImg, command=lambda: self.controller.showFrame("SetGrid"))

        self.canvas.pack()
        self.background.place(x=0, y=0, relwidth=1, relheight=1)
        self.solveButton.pack()
        self.quitButton.pack(pady=1)

class SetGrid(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.controller = controller

        self.canvas = tk.Canvas(self, bg="white", height=312, width=312)
        self.numberEntry = tk.Spinbox(self, state="readonly", width=2, wrap=True, justify="center", from_=0, to=9)
        self.solveButton = tk.Button(self, text="solve", command=self.solve)
        self.resetButton = tk.Button(self, text="reset", command=self.reset)
        self.returnButton = tk.Button(self, text="retour au menu", command=lambda: self.controller.showFrame("Menu"))

        self.canvas.pack()
        self.canvas.create_image(0, 0, anchor="nw", image=self.controller.gridbgImg)
        self.controller.displayGrid(self.canvas)
        self.numberEntry.pack(side="left", padx=10)
        self.solveButton.pack(side="right")
        self.resetButton.pack(side="right")
        self.returnButton.pack(side="right")

        self.canvas.bind("<Button-1>", self.setNumber)

    def setNumber(self, evt):
        x = int(evt.x / 35)
        y = int(evt.y / 35)

        self.controller.numberGrid[x][y] = int(self.numberEntry.get())
        self.controller.displayGrid(self.canvas)

    def solve(self):
        bufferString = ""
        for i in range(9):
            for j in range(9):
                bufferString += str(self.controller.numberGrid[i][j])
        print(bufferString)
        print(len(bufferString))
        print(sm.ft_solve(bufferString))
        self.controller.numberGrid = sm.ft_solve(bufferString)
        self.controller.displayGrid(self.canvas)

    def reset(self):
        for i in range(9):
            for j in range(9):
                self.controller.numberGrid[i][j] = 0
        self.controller.displayGrid(self.canvas)

#===CLASSE PLUS UTILISEE===
class DisplayGrid(tk.Frame):
    def __init__(self, parent, controller):
        tk.Frame.__init__(self, parent)
        self.controller = controller

        self.canvas = tk.Canvas(self, bg="white", height=315, width=315)
        self.returnButton = tk.Button(self, text="Retour au menu", command=self.reset)

        self.canvas.pack()
        self.controller.displayGrid(self.canvas)
        self.returnButton.pack()

    def reset(self):
        for i in range(9):
            for j in range(9):
                self.controller.numberGrid[i][j] = 0
        self.controller.showFrame("Menu")
#==========================

if __name__ == "__main__":
    app = SudokuSolver()
    app.mainloop()
