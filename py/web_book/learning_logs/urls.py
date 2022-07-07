from django.urls import path, include
from . import views

urlpatterns = [
    # Pagina Inicial
    path(r'', views.index, name='index'),
    # Mostra todos os assuntos 
    path(r'topics/', views.topics, name = 'topics'),
]