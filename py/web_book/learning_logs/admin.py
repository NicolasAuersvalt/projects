from django.contrib import admin
from learning_logs.models import Topic, Entry # Importa meu modelo Topic
# Register your models here.

admin.site.register(Topic) # Administra o código por meio do site de administração
admin.site.register(Entry)