"""from tkinter import *
from baidu import
# class tkinter.TK(screenName = None, baseName = None, className = "Baidul", useTk = 1)
texto = str()
baid = Tk()
baid.title = ("1 virus encontrado")
baid.geometry = ("1920x1080")
lab = Label(baid, text = texto, height= 5)
b1 = Button(baid, text = "Verificar", width=50)
lab.pack(), b1.pack()
baid.mainloop()

if b1.read() == True:
    texto == ("Achou")
    lab.pack(), b1.pack()

    software = Tk()
    software.title("Teste")
    software.geometry("1366x720")
    #Label(software, image=photo, width = 10).pack(side="top", pady=10)
    Label(software, text=rotulo, width=10, font=("Arial", 20)).pack(side="top", pady=10)
    Label(software, text=encontrado, width=30, height=20).pack(side="top", pady=30)
    button_one = Button(software, text="Verificação Rápida", width=30, command=verificacao_rapida)
    button_two = Button(software, text="Verificação Completa", width=30, command=verificacao_completa)
    button_key = Button(software, text="Ativar chave", width=10, command=ativacao())
    button_one.pack(side="left", padx=(200), pady=(200)), button_two.pack(side="right", padx=(200), pady=(200))
    button_key.pack(side="bottom", padx=(100))
"""
from tkinter import *
# from PIL import Image
from verificacao_completa import verificacao_completa
from verificacao_rapida import verificacao_rapida
import activation_key

# from data import local

file = open(r"C:\Users\nicol\Desktop\Antivirus\Local.txt", 'a')
file_key = open(r"C:\Users\nicol\Desktop\Antivirus\Ativação\chave_inserida.txt", "a")

def key_writte():
    file_key.write(enter_activation.get())
    enter_activation.delete(0, END)
    file_key.close()
    print("Chave Inserida")
    activation_key.ativacao()

def fil():
    file.write(endereco.get())
    endereco.delete(0, END)
    file.close()

# root = Tk()
pasta = r"C:\Users\nicol\PycharmProjects\pythonProject\Baidul"
lupa = r"C:\Users\nicol\Desktop\Antivirus\Lupa.png"
rotulo = "Antivairus"
encontrado = "Nenhuma ameaça detectada"
# photo = PhotoImage(file=lupa)
software = Tk()
software.title("Teste")
software.geometry("1366x720")
# Label(software, image=photo, width = 10).pack(side="top", pady=10)
Label(software, text=rotulo, width=10, font=("Arial", 20)).pack(side="top", pady=10)
Label(software, text=encontrado, width=30, height=20).pack(side="top", pady=30)
endereco = Entry(software, width=50)
enter_activation = Entry(software, width=30)
button_one = Button(software, text="Verificação Rápida", width=30, command=verificacao_rapida)
button_two = Button(software, text="Verificação Completa", width=30, command=verificacao_completa)
button_key = Button(software, text="Ativar chave", width=10, command=key_writte)
button_scan = Button(software, text="Escolher", width=10, command=fil)
button_one.pack(side="left", padx=(2), pady=(0, 20)), button_two.pack(side="right", padx=(2), pady=(0, 20))
button_key.pack(side="bottom", padx=(1)), button_scan.pack(), endereco.pack(), enter_activation.pack(side="bottom")
software.mainloop()
