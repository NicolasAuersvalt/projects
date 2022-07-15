from cgitb import text
from dataclasses import fields
from tkinter import Widget
from tkinter.ttk import LabeledScale
from .models import Topic, Entry
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
    
class EntryForm(forms.ModelForm):

    # Lista o modelo e o campo a ser incluido
    class Meta:
        model = Entry
        fields = ['text']

    # Rótulo vazio para o campo text
    labels = {'text': ''}

    # widgets é um elemento de formulário html

        # Ex: Uma caixa de texto de linha única
        # Área de texto
        # Ou lista suspensa

    # Ao usar forms.Textarea, estamos moldando widgets para que
    # Seja uma entrada de texto e tenha 80 colunas (default 40)
    widgets = {'text': forms.Textarea(attrs={'cols':80})}