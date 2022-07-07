from django.urls import path, include
from . import views

urlpatterns = [
    # Pagina Inicial
    path(r'^$', views.index, name='index'),
]