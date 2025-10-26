import tkinter
from tkinter import colorchooser

def drawLine(event) :
    global prevX, prevY
    x = event.x
    y = event.y
    if prevX != None and prevY != None :
         #line object created
        line = canvas.create_line(prevX, prevY, x, y, fill=color, width=6)
        lines.append(line)
    prevX = x
    prevY = y

def endLine(event) :
    global prevX, prevY
    prevX = None
    prevY = None

def changeColor() :
    global color
    chosen = colorchooser.askcolor()
    color = chosen[1]

def undo() :
    global lines
    if len(lines) > 0 :
        # line object will be deleted
        line = lines.pop()
        canvas.delete(line)
        
        

lines = []
prevX = None
prevY = None
color = "red"

window = tkinter.Tk()
window.title("My Photoshop")

img = tkinter.PhotoImage(file="kitty.gif")
canvas = tkinter.Canvas(window, width=img.width(), height=img.height())
canvas.pack()

canvas.create_image(0, 0, anchor="nw", image=img)
canvas.bind("<B1-Motion>", drawLine)
canvas.bind("<ButtonRelease-1>", endLine)

tkinter.Button(window, text="색상 고르기", command=changeColor).pack()
tkinter.Button(window, text="Undo", command=undo).pack()
