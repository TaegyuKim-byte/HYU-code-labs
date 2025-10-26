import tkinter

img_list = ['''
/-----------------------\\
|                       |              |~~\\_____/~~\\__   
|      Asciimation      |______________ \\______====== )-+
|                       |                      ~~~|/~~   
\\-----------------------/                         ()
''',
'''
/-----------------------\\
|                       |              |~~\\_____/~~\\__  |  
|      Asciimation      |______________ \\______====== )-+
|                       |                      ~~~|/~~  |
\\-----------------------/                         ()
''']
    
def close() :
    global loop
    loop = False
    window.destroy()

window = tkinter.Tk()
window.protocol("WM_DELETE_WINDOW", close)

canvas = tkinter.Canvas(window, width=800, height=400)
canvas.pack()

frame = tkinter.Frame(window)
frame.pack()

count = 0
loop = True
t1 = canvas.create_text(-450, 20, anchor="nw", text=img_list[0], font="courier")
while loop :
    canvas.itemconfig(t1, text=img_list[count % 2]) #0번과 1번 이미지가 반복되게
    canvas.move(t1, 3, 0)
    # time delay for 100ms
    canvas.after(100)
    canvas.update()
    count = count + 1
