
import speech_recognition as sr

r = sr.Recognizer()
with sr.Microphone() as source:
    print("Start Talk")
    audio_text = r.listen(source)
    print("Time over!, thanks")
    
    try:
        text = r.recognize_google(audio_text)
        print(text)
        text.replace(" ","_")()
    except:
         print("Sorry, I did not get that Run again!")