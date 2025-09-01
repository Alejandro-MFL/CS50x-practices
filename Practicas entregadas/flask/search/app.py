from cs50 import SQL
from flask import Flask, render_template, jsonify, request

app = Flask(__name__)

db = SQL("sqlite:///songs.db")


@app.route("/")
def index():
    return render_template("index.html")


@app.route("/search")
def search():
    # Esto se usa para que busque coincidencia desde ambos lados, no solo para que busque que inicie igual
    query = request.args.get("q")
    if query :
        songs = db.execute("SELECT * FROM songs WHERE name LIKE ? LIMIT 20", "%" + query + "%")
    else:
        songs = []
    return jsonify(songs)
    # Esta parte era para usar html
    # return render_template("search.html", songs=songs)
