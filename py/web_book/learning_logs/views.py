from django.http import HttpResponse, HttpResponseRedirect
from django.shortcuts import render
from .models import Topic, Entry
from .forms import TopicForm

# Create your views here

def index(request):
    # Pagina inicial de Leaning Log
    return render(request, 'learning_logs/index.html')

# A função exige um parâmetro: o objeto request recebido do servidor
def topics(request): # Mostra todos os assuntos
    
    # Então consultamos o banco de dados solicitando objetos topic com 
        # atributo date_added
        # armazenamos o queryset resultante em topics
    topics = Topic.objects.order_by('date_added')

    # Definimos o contexto enviado ao template
    # Contexto é um dicionário em que:

        # chaves = nomes que usaremos no template para acessar dados;
        # valores = dados que devemos enviar ao template.
        # neste caso há apenas um par chave e valor, que são os assuntos
    context = {'topics': topics}

    # Ao construir um página que use dados, passamos context ao Render, além do objeto
    # request e path do template
    return render(request, 'learning_logs/topics.html', context)

def topic(request, topic_id): # Mostra um assunto e todas as suas entradas

    topic = Topic.objects.get(id=topic_id)

    #-date_added exibe a data da Mais Recente para a Menos Recente
    entries = topic.entry_set.order_by("-date_added")
    context = {'topic' : topic, 'entries' : entries}
    
    return render(request, 'learning_logs/topic.html', context)

def new_topic(request):

    # Nenhum dado submetido. Cria um formulário em branco

        # Caso não seja POST, sempre será um GET
    if request != 'POST': 

        # Por ser GET, devolve um formulário em branco.
        form = TopicForm()
    else:

        # Sendo POST, vai receber e processar os dados
        form = TopicForm(request.POST)

        # A função is_valid() verifica se o tipo é compatível com o requisitado:

            # Por exemplo text com 200 caracteres.
        if form.is_valid():

            # Se caso estiver certo, chamará o save()

                # E depois grava no banco de dados
            form.save
            
            # Obtemos o url da pagina e passamos para HttpResponse

                # Este que direciona o navegador do usuário para essa página
            return HttpResponseRedirect(reverse('learning_logs:topics'))

    context = {'form': form}

    return render(request, 'learning_logs/new_topic.html', context)

    # Temos alguns tipos de requisições: GET e POST

    # GET para páginas que apenas leem dados do servidor

    # POST quando o usuário precisa submeter informações por formulário

        # Formulário em branco, o navegador manda GET e o servidor intepreta como no código acima

        # Formulário preenchido, o navegador envia um POST que, caso não seja, sempre será um GET

        # Então o servidor faz o digitado acima