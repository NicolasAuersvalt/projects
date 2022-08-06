from django.urls import re_path, path
from . import views

# Favicon
from django.contrib.staticfiles.storage import staticfiles_storage
from django.views.generic.base import RedirectView

urlpatterns = [

    re_path(r'^$', views.index, name="index"),

    re_path(r'^WitBot/$', views.witbot, name="witbot"),

    re_path(r'^Game/$', views.game, name="game"),

    path('favicon.ico', RedirectView.as_view(url=staticfiles_storage.url('static/favicon/favicon.ico')))

]
app_name = "website"