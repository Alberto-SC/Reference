import os
requiredCommands = ['Description','time']
languagesExtensions = ['c','cpp','py','java','h','rs','sh','txt','rs']

class IncompleteCommands(Exception):
     def __init__(self, file, missedCommands):
        self.file = file
        self.missedCommands = missedCommands
        super().__init__(f'The file {file} is missing some commands set as required ({missedCommands}), it will be treated as a raw file without metadata')

class NotCommands(Exception):
    def __init__(self, file, message):
        self.file = file
        self.message = message
        super().__init__(f'The file {file} not contain the defined commands, it will be treated as a raw file without metadata')

class IncorrectCommand(Exception):
    def __init__(self, command):
        self.command = command
        super().__init__(f'The command {command} is not correct , it will be ignored')

class InvalidMetadata(Exception):
    def __init__(self,metadata):
        self.file = file
        self.message = message
        super().__init__(f'The file {file} not contain the defined commands, it will be treated as a raw file without metadata')

class NotProgrammingLanguageOrText(Exception):
    def __init__(self, file):
        self.file = file
        super().__init__(f'The file {file} is not a programming code or text file or is a language not consider, considered languages are {languagesExtensions}')
