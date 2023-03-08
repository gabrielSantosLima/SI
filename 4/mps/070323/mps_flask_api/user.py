from datetime import datetime

from flask import abort, make_response


def get_timestamp():
    return datetime.now().strftime('%Y-%m-%d %H:%M:%S')

USER = {
    "1000": {
        "user_name": "Caio Rolando",
        "user_id": "1000",
        "timestamp": get_timestamp()
    },
    "1001": {
        "user_name": "Gabriel Lima",
        "user_id": "1001",
        "timestamp": get_timestamp()
    },
    "1002": {
        "user_name": "Ednaldo Pereira",
        "user_id": "1002",
        "timestamp": get_timestamp()
    }
}

def read_all():
    return list(USER.values())

def read_one(user_id):
    if user_id in USER:
        return USER[user_id]
    abort(404, f"User not found with id {user_id}")

def create(user):
    if not user["user_id"] in USER: 
        USER[user["user_id"]] = {
            "user_name": user["user_name"],
            "user_id": user["user_id"],
            "timestamp": get_timestamp()
        }
    return USER[user["user_id"]]