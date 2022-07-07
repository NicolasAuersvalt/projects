"""
Objetivo é fazer a verificação se as palavras chmod, ssh, JohnTheRipper, ssh2john.py estão contidas dentro do arquivo.
"""
import shutil
encontrado = "Nenhuma ameaça detectada"


def verificacao_completa():
    abrido = open(r"C:\Users\nicol\Desktop\Antivirus\Local.txt", 'r')
    arquivo = str(abrido.read())
    print("Este é o {}".format(arquivo))
    #arquiva = r"C:\Users\nicol\Desktop\Antivirus\Pasta para Verificação\hardwareLog.txt"
    arquiva = arquivo
    quarentena = r"C:\Users\nicol\Desktop\Antivirus\Quarentena\error_log.txt"
    arquivoc = open(arquiva, "r")
    filec = arquivoc.read()
    exploitc = filec.find("chmod", "ssh", "JohnTheRipper", "ssh2john.py")
    print(exploitc)
    if exploitc != -1:
        ispresent = True
    else:
        ispresent = False
    arquivoc.close()
    print(ispresent)

    if ispresent == True:
        #shutil.move(arquivo, quarentena)
        encontrado = f"{x} \n movido para Quarentena"
    return
