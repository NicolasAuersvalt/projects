"""
Objetivo é fazer a verificação se a palavra chmod contida dentro do arquivo.
"""
import shutil
encontrado = "Nenhuma ameaça detectada"
def verificacao_rapida():
    abrido = open(r"C:\Users\nicol\Desktop\Antivirus\Local.txt", 'r')
    arquivo = str(abrido.read())
    print("Este é o {}".format(arquivo))
    #arquivo = r"C:\Users\nicol\Desktop\Antivirus\Pasta para Verificação\error_log.txt"
    #arquivo 2 = C:\Users\nicol\Desktop\Antivirus\Pasta para Verificação\hardwareLog.txt
    quarentena = r"C:\Users\nicol\Desktop\Antivirus\Quarentena\error_log.txt"
    arquivof = open(arquivo, "r")
    filef = arquivof.read()
    exploit = filef.find("chmod")
    print(exploit)
    if exploit != -1:
        ispresent = True
    else:
        ispresent = False
    arquivof.close()
    print(ispresent)

    if ispresent == True:
        #shutil.move(arquivo, quarentena)
        encontrado = "Um arquivo suspeito \n movido para Quarentena"
    return
