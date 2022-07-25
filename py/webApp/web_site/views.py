from multiprocessing import context
from django.shortcuts import render
from .models import Topic, Entry

# Create your views here.

def index(request):
    return render(request, 'web_site/index.html')

def topic(request):
    topic = Topic.objects.order_by('date_added')
    context = {'topic':topic}

    return render(request, 'web_site/index.html', context)

def witbot(request):
    topic = Topic.objects.order_by('date_added')
    context={'topic':topic}

    return render(request, 'web_site/witbot.html', context)

def game(request):
    topic = Topic.objects.order_by('date_added')
    context = {'topic':topic}

    return render(request, 'web_site/game.html', context)