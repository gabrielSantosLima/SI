import turtle

score_1 = 0
score_2 = 0

def move_up(turtle: turtle.Turtle):
  y = turtle.ycor()
  if(y < 250): y += 30
  else: y = 250
  turtle.sety(y)

def move_down(turtle: turtle.Turtle):
  y = turtle.ycor()
  if(y > -250): y += -30
  else: y = -250
  turtle.sety(y)

def move_ball(ball: turtle.Turtle, player_1: turtle.Turtle, player_2: turtle.Turtle):
  if(ball.ycor()> 290):
    ball.sety(290)
    ball.dy *= -1

  if(ball.ycor() < -290):
    ball.sety(-290)
    ball.dy *= -1
  ball.setx(ball.xcor() + ball.dx)
  ball.sety(ball.ycor() + ball.dy)

  if(ball.xcor() < -390):
    global score_2
    score_2 += 1
    ball.goto(0,0)
    ball.dx *= -1

  if(ball.xcor() > 390):
    global score_1
    score_1 += 1
    ball.goto(0,0)
    ball.dx *= -1

def main():
  print(score_1)
  screen = turtle.Screen()
  screen.title('Meu Jogo')
  screen.bgcolor('black')
  screen.setup(width=800, height=660)
  screen.tracer(0)

  player_1 = turtle.Turtle()
  player_1.speed(0)
  player_1.shape('square')
  player_1.color('white')
  player_1.shapesize(stretch_wid=5, stretch_len=1)
  player_1.penup()
  player_1.goto(-350, 0)

  player_2 = turtle.Turtle()
  player_2.speed(0)
  player_2.shape('square')
  player_2.color('white')
  player_2.shapesize(stretch_wid=5, stretch_len=1)
  player_2.penup()
  player_2.goto(350, 0)
  
  ball = turtle.Turtle()
  ball.speed(0)
  ball.shape('square')
  ball.color('white')
  ball.penup()
  ball.goto(0, 0)
  ball.dx = 1
  ball.dy = 1

  hud = turtle.Turtle()
  hud.speed(0)
  hud.shape('square')
  hud.color('white')
  hud.hideturtle()
  hud.penup()
  hud.goto(0, 260)
  hud.write(f"{score_1} : {score_2}", align="center", font=("Roboto", 24, "normal"))

  screen.listen()
  screen.onkeypress(lambda: move_up(player_1), "Up")
  screen.onkeypress(lambda: move_down(player_1), "Down")
  screen.onkeypress(lambda: move_up(player_2), "w")
  screen.onkeypress(lambda: move_down(player_2), "s")

  # add_colision(ball, player_1)
  # add_colision(ball, player_2)

  while True:
    hud.clear()
    hud.write(f"{score_1} : {score_2}", align="center", font=("Roboto", 24, "normal"))
    move_ball(ball, player_1, player_2)
    screen.update()

main()