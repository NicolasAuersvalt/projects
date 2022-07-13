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
    re_path(r'^$', views.index, name='index'),

    # Mostra todos os assuntos 
    re_path(r'^topics/$', views.topics, name='topics'),

    # Mostra os assuntos individuais
    re_path(r'^topics/(?P<topic_id>\d+)/$', views.topic, name='topic'),

    # Mostra o novo assunto
    re_path(r'^new_topic/$', views.new_topic, name = 'new_topic'),
    
    # route as regular expressions
        
        # str - Matches any non-empty string, excluding the path separator, '/'. This is the default if a converter isn’t included in the expression.
        
        # int - Matches zero or any positive integer. Returns an int.
        
        # slug - Matches any slug string consisting of ASCII letters or numbers,
            # plus the hyphen and underscore characters. For example, building-your-1st-django-site.

        # uuid - Matches a formatted UUID. To prevent multiple URLs from mapping to the same page,
            # dashes must be included and letters must be lowercase. For example, 075194d3-6885-417e-a8a8-6c931e272f00.
            #  Returns a UUID instance.

        # path - Matches any non-empty string, including the path separator, '/'.

        # This allows you to match against a complete URL path rather than a segment of a URL path as with str.
]
app_name = "learning_logs"