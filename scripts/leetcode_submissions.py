"""
this scripts needs httpx to be installed
https://www.python-httpx.org/
"""
import os
import sys
from os.path import exists, expanduser
from subprocess import check_output

from httpx import Client

# we need the COMPETITIVE_FOLDER, LEETCODE_CSRFTOKEN and LEETCODE_SESSION enviromental variables
competitive_folder = expanduser(os.environ.get("COMPETITIVE_FOLDER", "./leetcode"))
cookies = {
    "LEETCODE_SESSION": os.environ.get("LEETCODE_SESSION", ""),
    "csrftoken": os.environ.get("LEETCODE_CSRFTOKEN", ""),
    "NEW_PROBLEMLIST_PAGE": "1",
}

submitted = {}
limit = int(os.environ.get("LEETCODE_LIMIT", 100))

print(f"changing directory to {competitive_folder}")
os.chdir(competitive_folder)

client = Client(
    base_url="https://leetcode.com/api/submissions",
    headers={
        "Referer": "https://leetcode.com/submissions",
    },
)

params = {"limit": limit}

response = client.get("/", params=params, cookies=cookies)
cookies.update(response.cookies)
cookies = response.cookies
res = response.json()


if response.status_code == 200:
    for submission in res["submissions_dump"]:
        extension = ""
        if submission["lang"] == "cpp":
            extension = "cpp"
        else:
            extension = "py"

        filename = f'{submission["title_slug"]}.{extension}'
        if (
            filename not in submitted
            and submission["status"] == 10
            and (
                not exists(filename)
                or submission["timestamp"]
                > int(
                    check_output(["git", "log", "-n 1", "--format='%at'", filename])
                    .decode(sys.stdout.encoding)
                    .strip()
                    .replace("'", "")
                )
            )
        ):
            submitted[filename] = submission

for filename, submission in reversed(submitted.items()):
    message = f'{submission["title_slug"]}\n\nhttps://leetcode.com/problems/{submission["title_slug"]}\n\n{submission["runtime"].replace(" ", "")} {submission["memory"].replace(" ", "").lower()}'

    print(f"writing {submission['title_slug']}")
    file = open(filename, "w")
    file.write(submission["code"])
    file.close()

    os.system("git reset")
    if filename.split(".")[-1] == "py":
        os.system(f"black {filename}")
    os.system(f"git add {filename}")
    os.system(f'git commit -m "{message}"')
