"""
this scripts needs httpx to be installed
https://www.python-httpx.org/
"""
import os
from os.path import exists, expanduser

from httpx import Client

# we need the COMPETITIVE_FOLDER and LEETCODE_COOKIE enviromental variables
competitive_folder = expanduser(os.environ.get("COMPETITIVE_FOLDER", "./leetcode"))
cookie = os.environ.get("LEETCODE_COOKIE", "")

print(f"changing directory to {competitive_folder}")
os.chdir(competitive_folder)


client = Client(
    base_url="https://leetcode.com/api/submissions",
    headers={
        "Referer": "https://leetcode.com/submissions",
        "Cookie": cookie,
    },
)

offset = 0
limit = int(os.environ.get("LEETCODE_LIMIT", 100))
last_key = None

submissions = {}

while True:
    params = {"limit": limit, "offset": offset}
    if last_key:
        params["lastkey"] = last_key

    response = client.get("/", params=params)
    res = response.json()

    if response.status_code != 200:
        break

    for submission in reversed(res["submissions_dump"]):
        extension = ""
        if submission["lang"] == "cpp":
            extension = "cpp"
        else:
            extension = "py"

        filename = f'{submission["title_slug"]}.{extension}'
        if submission["status"] == 10 and not exists(filename):
            message = f'{submission["title_slug"]}\n\nhttps://leetcode.com/problems/{submission["title_slug"]}\n\n{submission["runtime"].replace(" ", "")} {submission["memory"].replace(" ", "").lower()}'

            print(f"writing {submission['title_slug']}")
            file = open(filename, "w")
            file.write(submission["code"])
            file.close()

            os.system("git reset")
            if extension == "py":
                os.system(f"black {filename}")
            os.system(f"git add {filename}")
            os.system(f'git commit -m "{message}"')

    last_key = res["last_key"]
    if not res["has_next"]:
        break

    offset += limit
