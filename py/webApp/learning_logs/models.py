from django.db import models

# Create your models here.
class Topic(models.Model):
    text = models.CharField(max_length=200) # CharField é um dado composto de caracteres (pequena quantidade. Ex: Nome)
    # Max_length -> Está definindo um espaço no banco de dados
    date_added = models.DateTimeField(auto_now_add=True) # DataTimeField é um dado que registra data e hora
    # auto_now_add=True Django definirá automaticamente com data e hora

    def __str__(self): # Devolve uma representação em string do modelo
        return self.text # Neste caso, text

class Entry(models.Model): 
    topic = models.ForeignKey(Topic, on_delete=models.PROTECT)
    """
    # Instância do Foreign
    # ForeignKey (Chave Estrangeira) se refere a outro registro do banco de dados
    # Cada assunto recebe um ID para podermos relacioná-los depois
    # Xadrez = 1, Livro = 2
    # Quando o Django quiser estabelecer uma conexão entre os dois, ele vai chamar pela chave
    # """
    
    text = models.TextField()
    date_added = models.DateTimeField(auto_now_add = True)

    class Meta: 
        verbose_name_plural = 'entries'
    def __str__(self):
            return self.text
        