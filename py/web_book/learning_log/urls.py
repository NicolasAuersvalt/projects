"""learning_log URL Configuration

The `urlpatterns` list routes URLs to views. For more information please see:
    https://docs.djangoproject.com/en/4.0/topics/http/urls/
Examples:
Function views
    1. Add an import:  from my_app import views
    2. Add a URL to urlpatterns:  path('', views.home, name='home')
Class-based views
    1. Add an import:  from other_app.views import Home
    2. Add a URL to urlpatterns:  path('', Home.as_view(), name='home')
Including another URLconf
    1. Import the include() function: from django.urls import include, path
    2. Add a URL to urlpatterns:  path('blog/', include('blog.urls'))
"""
from django.contrib import admin
from learning_logs import views
from django.urls import include, path

import learning_logs

urlpatterns = [
    # path (route, view, **kwargs, name)
    # path('admin/', admin.site.urls), path(r'', 'learning_logs.urls', namespace = 'learning_logs'),

        # include(module, namespace=None)¶
        # include(pattern_list)
        # include((pattern_list, app_namespace), namespace=None)

            # module – URLconf module (or module name)
            # namespace (str) – Instance namespace for the URL entries being included
            # pattern_list – Iterable of path() and/or re_path() instances.
            # app_namespace (str) – Application namespace for the URL entries being included


    path(r'admin/', admin.site.urls), 
    path(r'', include('learning_logs.urls', namespace = 'learning_logs')),
]


