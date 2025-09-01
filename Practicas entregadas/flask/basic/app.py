from flask import Flask, render_template, request

app = Flask(__name__)


@app.route("/", methods=["GET", "POST"])
def index():
    if request.method == "POST":
        #name = request.form.get("name", "dude")
        # Por convencion, se suele utilizar el mismo nombre para el mismo parametro en los distintos elementos
        return render_template("greet.html", name=request.form.get("name"))
    else:
        return render_template("index.html")




#if __name__ == "__main__":
 #   app.run(debug=True)
