from cs50 import SQL
from flask import Flask, render_template, redirect, request, session
from flask_session import Session

app = Flask(__name__)

db = SQL("sqlite:///froshims.db")

SPORTS = [ "Basketball", "Soccer", "Petanque",]
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

@app.route("/", methods=["GET"])
def index():
    return render_template("index.html", sports=SPORTS)


@app.route("/", methods=["POST"])
def registered():
    name = request.form.get("name")
    sports = request.form.get("sports")
    if not name:
        return render_template("error.html", message="A name is not registered")
    elif not sports:
        return render_template("error.html", message="A sport is not registered")
    elif sports not in SPORTS:
        return render_template("error.html", message="No valid sport is registered")
    else:
        db.execute("INSERT INTO registrants (name, sport) VALUES (?,?)", name, sports)
        return render_template("success.html", name=name, sports=sports)

@app.route("/registrants", methods=["GET", "POST"])
def showRegistration():
    registrants = db.execute("SELECT name, sport FROM registrants")
    return render_template("registered.html", registrants=registrants, user=session.get("user"))

@app.route("/login", methods=["GET", "POST"])
def login():
    if request.method == "POST":
        session["user"] = request.form.get("user")
        return redirect("/registrants")
    return render_template("login.html")

@app.route("/logout")
def logout():
    session.clear()
    return redirect("/")
