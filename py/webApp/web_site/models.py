from typing import Text
from django.db import models

class Topic(models.Model):
    '''
    Bloco dedicado à introdução de assuntos
    '''
    text = models.CharField(max_length=50)
    date_added = models.DateTimeField(auto_now_add=True)
    def __str__(self):
        return self.text

class Entry(models.Model):
    '''
    Bloco definido à introdução de texto dos assuntos
    '''
    text = models.TextField()
    entry = models.ForeignKey(Topic, on_delete=models.PROTECT)
    date_added = models.DateTimeField(auto_now_add=True)

    class Meta():
        verbose_name_plural = 'entries'
    def __str__(self):
            return self.text