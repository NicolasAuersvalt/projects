from django.urls import path, include, re_path
from . import views

urlpatterns = [
    # path (route, view, **kwargs, name)

    # The route argument should be a string or gettext_lazy() that contains a URL pattern.
    # The string may contain angle brackets (like <username> above) 
    # to capture part of the URL and send it as a keyword argument to the view.
    # The angle brackets may include a converter specification 
    # (like the int part of <int:section>) which limits the characters matched and may also change
    # the type of the variable passed to the view. 
    # EX: <int:section> matches a string of decimal digits and converts the value to an int.
 
    # The view argument is a view function or the result of as_view() for class-based views.
    # It can also be an django.urls.include().

    # Pagina Inicial
    re_path(r'', views.index, name='index'),

    # Mostra todos os assuntos 
    re_path(r'ˆtopics(?P<topic_id>\d+)$', views.topics, name = 'topics'),
]
app_name = "learning_logs"