"""
Define padroes de URL para learning_logs.
"""

from django.conf.urls import url 
from . import views

urlpatterns = [
    # Pagina inicial 
    path(r'^$', views.index, name = 'index'),

]
