from django.shortcuts import render
from .models import Topic

# Create your views here

def index(request):
    # Pagina inicial de Leaning Log
    return render(request, 'learning_logs/index.html')

def topics(request): # Mostra todos os assuntos
    # A função exige um parâmetro: o objeto request recebido do servidor
    
    # Então consultamos o banco de dados solicitando objetos topic com 
    # atributo date_added
    # armazenamos o queryset resultante em topics
    topics = Topic.objects.order_by('date_added')
    
    # Definimos o contexto enviado ao template
    # Contexto é um dicionário em que:

    # chaves = nomes que usaremos no template para acessar dados;
    # valores = dados que devemos enviar ao template.
    
    # neste caso há apenas um par chave e valor, que são os assuntos
    context = {'topics' : topics}

    # Ao construir um página que use dados, passamos context ao Render, além do objeto
    # request e path do template
    return render(request, 'learning_logs/topics.html', context)