from cgitb import text
from .models import Topic
from django import forms

class TopicForm(forms.ModelForm):
    class Meta:
        # Qual modelo django deve se basear e quais campos devem ser definidos

        # Criamos um formulário a partir de Topic
        model = Topic
        
        # Campo text
        fields = ['text']

        # Não gerar um rótulo para o campo text
        labels = {'text':''}