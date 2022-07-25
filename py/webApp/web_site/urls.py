from django.urls import re_path
from . import views

urlpatterns = [

    re_path(r'^$', views.index, name="index"),

    re_path(r'^WitBot/$', views.witbot, name="witbot"),

    re_path(r'^Game/$', views.game, name="game"),

]
app_name = "website"