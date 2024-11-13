from requests import *
import random
from faker import Faker
from time import sleep



faker = Faker()
api_url = "http://pwny.shellmates.club/api"
admin_token = "eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySUQiOjEsInVzZXJuYW1lIjoiYWRtaW4iLCJpYXQiOjE3MzEwNzUyMjUsImV4cCI6MTczMzY2NzIyNX0.DyU7Bwf-zkzkO14kaAaiF9sJT5Ic7sL8JqWiAW4cmx8"

def get_token(username,password):
    r = post(api_url+"/auth/login",headers={
        "Content-Type": "application/json",
        },json={
            "username":username,
            "password":password
        }
    )
    sleep(0.1)
    return r.json()["token"]

def get_users():
    r = get(api_url+"/users",headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}"
        }
    )
    return r.json()

def create_categories():
    CATEGORIES = [("Pwn","Binary Exploitation"),("Rev","Reverse Engineering"),("Web","Web Exploitation"),("Crypto","Cryptography"),("DFIR","Digital Forensics & Incident Response")]
    
    for c in CATEGORIES:
        r = post(api_url+"/categories",headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {admin_token}"
            },json={
                "name":c[0],
                "description":c[1]
            }
        )
        
    return r.json()

def create_users(num):
    
    obj = {
        "fullName":"a",
        "username":"b",
        "password":"password",
        "phoneNumber":"0531241414",
        "email": "ls_djerrai@esi.com",
        "confirmed": True
    }
    
    for _ in range(num):
        obj["fullName"] = faker.first_name()
        obj["username"] = faker.user_name()
        obj["email"] = faker.email()

    
        r = post(api_url+"/auth/register",headers={
            "Content-Type": "application/json",
            },json=obj
        )
        
    return r.json()

def create_challenges(num):
    DIFFIULTIES = ["easy","medium","hard"]
    challenge = {
        "name":"name",
        "description":"description",
        "flag":"shellmates{}",
        "link":"http://127.0.0.1/test",
        "author":"test",
        "difficulty": "easy"
    }
    for _ in range(num):
        challenge["name"] = f"test{_}"
        challenge["description"] = f"description{_}"
        challenge["author"] = f"author{_}"
        challenge["flag"] = f"shellmates{'{'+str(_)+'}'}"
        challenge["link"] = f"http://google.com/?c={_}"
        challenge["difficulty"] = random.choice(DIFFIULTIES)
        challenge["categoryId"] = random.choice(list(range(1,6)))
        
        
        r = post(api_url+"/challenges",headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {admin_token}"
            },
            json=challenge,
        )
        
    return r.json()     

def create_round(title,description,nbWinners):
    
    r= post(api_url+"/rounds",headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}" 
        },
        json={
            "title":title,
            "description":description,
            "nbWinners":nbWinners
        }
    )
    
    return r.json()

def create_racing(roundId):
    r = post(api_url+"/racings",headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}" 
        },
        json={
            "roundId":roundId,
        }
    )
    
    return r.json()

def set_racing_users(racingId,participantsIds):
    r = post(api_url+f"/racings/users",headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}" 
        },
        json={
            "racingId": racingId,
            "participantsIds":participantsIds
        }
    )
    
    return r.json()

def set_racing_challenges(racingId,challengesIds):
    r = post(
        api_url+f"/racings/challenges",
        headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}"
        }
        ,json={
            "racingId":racingId,
            "challengesIds":challengesIds
        }
    )
    
    return r.json()

def submit_challenge(username,password,challengeId,flag):
    token = get_token(username,password)
    
    r = post(
        api_url+f"/challenges/{challengeId}/submit",
        headers={
            "Content-Type": "application/json",
            "Authorization": f"Bearer {token}"
        },
        json={
            "flag":flag
        }
    )
    return r.json()

def get_user_ids():
    r = get(api_url+"/users",headers={
        "Content-Type": "application/json",
        "Authorization": f"Bearer {admin_token}"
        }
    )
    return [u["id"] for u in r.json()]

def do_create_1():
    create_categories()
    create_users(32)
    create_challenges(20)
    create_round("1st Elimination","Only the top 16 players will qualify to the next round",16)

def do_create_2():
    pass
    # create_racing(1)
    # set_racing_users(1,get_user_ids())
    # set_racing_challenges(1,[7,2,5])
    
def do_create_3():
    
    users = get_users()
    
    for u in users:
        print(u['username'])
        submit_challenge(u["username"],"password",65,"shellmates{4}")
        sleep(0.2)

# set_racing_users(26,get_user_ids())
create_categories()
# create_challenges(20)
