import speech_recognition as sr
import pygame
import requests
from io import BytesIO

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Start Talk")
    audio_text = r.listen(source)
    print("Time over!, thanks")
    try:
        word = r.recognize_google(audio_text)
        print(word)
    except:
         print("Sorry, I did not get that Run again!")

response = requests.get("https://api.dictionaryapi.dev/api/v2/entries/en/"+ word)
data = eval(response.text)
print(word + " meaning :" + data[0]["meanings"][0]["definitions"][0]["definition"])
audio_url =data[0]["phonetics"][0]["audio"]

# Initialize pygame mixer
pygame.mixer.init()
# Load audio from URL
response = requests.get(audio_url)
audio_data = BytesIO(response.content)
# Load and play audio
pygame.mixer.music.load(audio_data)
pygame.mixer.music.play()
while pygame.mixer.music.get_busy():
    pygame.time.Clock().tick(1)