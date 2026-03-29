#import "@preview/touying:0.6.1": *
#import themes.university: *
#import "@preview/fletcher:0.5.8" as fletcher: diagram, edge, node

#show: university-theme.with(
  aspect-ratio: "16-9",
  config-info(
    title: [Trickle-Down Dragonslayer],
    author: [Peter Chaplin-Smith, Louis Lear-Belcher, Heath Mitchell],
    date: datetime.today(),
    institution: [Bath Hack 2026],
  ),
  config-colors(
    primary: rgb("#a10125"),
    secondary: rgb("#b6484f"),
    tertiary: rgb("#bf6065"),
    neutral-lightest: rgb("#ffffff"),
    neutral-darkest: rgb("#000000"),
  ),
  //config-common(handout: true),
)

#set cite(style: "alphanumeric")

// regex magic to make citations coloured in both text and bibliography
#show bibliography: it => {
  show regex("^\[[\p{L}\d+]+\]"): m => {
    show regex("[\p{L}\d+]+"): set text(fill: rgb("#a10125"))
    m
  }
  it
}

#show cite: it => {
  show regex("[\p{L}\d+]+"): set text(fill: rgb("#a10125"))
  it
}

// style external links
#show link: it => {
  if type(it.dest) != label and type(it.dest) != location {
    set text(fill: rgb("#a10125"), font: "FreeMono")
    it
    sym.wj
    h(1.6pt)
    sym.wj
    super(box(height: 0.33em, circle(
      radius: 2pt,
      stroke: 0.7pt + rgb("#01a17d"),
    )))
  } else {
    it
  }
}

#let listing = figure.with(supplement: "Listing")

#title-slide()

= Humble Beginnings

== The Idea

The plan was simple... #pause bring AI to the Apple \/\/e. #pause

#align(center, diagram(
  node(
    (0, 0),
    "Local AI Model",
    stroke: 0.5pt,
    corner-radius: 0.3em,
    name: <local-model>,
  ),
  node(
    (2, 0),
    "Apple //e",
    stroke: 0.5pt,
    corner-radius: 0.3em,
    name: <apple>,
  ),
  edge(<local-model>, <apple>, "<->", label: "Serial"),
)) #pause

We'd use a Super Serial Card and create a null modem to let the Apple and local AI model. #pause

Everyone was afraid of communism in the 80s. What about an AI-guided text-based cold-war adventure game! #pause

What could go wrong?

= Disaster Strikes

== Oh No

At 11:32 PM, Louis was getting the Apple \/\/e ready with Apple DOS. #pause Unfortunately, he did this while his washing, drying, and desktop was running. #pause His breaker box did not appreciate this. #pause Nor, did the Apple \/\/e:

#align(center, image("media/disaster.png", height: 65%))

== Still Oh No

At 09:15 AM, Louis sent "We've had a nightmare, think my IOU chip is dead" to the team groupchat. #pause

Some quick debugging, but all attempts to fix the Apple \/\/e before hacking began were to no avail. #pause Could it be the clock? #pause The IOU? #pause The CPU? #pause Only time would tell.

At 11:57 AM we made our way up to the hardware lab. #pause We frantically pulled components from our donor board. #pause First was the LS245#pause, then the LS244s. #pause Nothing. #pause Out came the big guns, probing with an oscilloscope like madmen. #pause The CD ROM? #pause Nope.

#pagebreak()

#align(center + horizon, image("media/probing.jpg", height: 90%))

#pagebreak()

Wait, what does the EF ROM even do? #pause

#align(center, image("media/success.jpg", height: 80%))

#pagebreak()

#align(center, image("media/borked.png"))

= Back On Track

== Sort Of

All we need to do is get the Super Serial Card working... #pause Step 1: Make a null modem:

#align(center, image("media/null_modem.png", height: 75%))

#pagebreak()

- Step 2: Get the Super Serial Card working. #pause
- Step 3: Find a sufficiently bad local AI model. #pause
- Step 4: Get the Super Serial Card working. #pause
- Step 5: Get the Super Serial Card working. #pause

#align(center, image("media/not_working.jpg", height: 55%))


#pagebreak()
- Step 6: Think of plan B. #pause
- Step 7: Maybe we can read data from the cassette at runtime? #pause
- Step 8: Why don't we just try write a game without the AI in Applesoft BASIC? #pause
- Step 9: `SYNTAX ERROR AT 32`, but there is no syntax error? #pause Removing line `32` didn't help... #pause
- Step 10: Let's try an online C compiler/IDE... #pause
- Step 11: Oh that works! And it's only... #pause 04:12 AM??!?!1


#pagebreak()

= Okay, Now We're Back

== Market Strategy

Now that our technical woes are behind us, we can finally focus on our business strategy! #pause

#align(center, image("media/stonks.png", height: 75%))

== Marketing Materials

TODO

== The Finished Product

#pause
- A fixed Apple \/\/e #pause
- A borked EF ROM #pause
- A useless Super Serial Card (dodgy clone from '84) #pause
- A broken BASIC game #pause
- A program that reads from the cassette at 2 charaters a second #pause
- Over six hundred lines of messy C89 #pause

#align(center, text(size: 2em)[Trickle-Down Dragonslayer])

= Bugger

== Disaster

#pause
09:56 AM. #pause Capacitor in the PSU blows. #pause All the magic smoke poured out.

#pause
Stright to the hardware lab. #pause Nothing usable.

#pause
A little birdy told us about a broken unused microwave that _may_ just have the 250V 47$mu$F capacitor we need.

#pause
Screwdrivers in hand, we headed off to tear the microwave apart.

#pagebreak()

#align(center, image("media/microwave-open.jpg", height: 90%))

#pagebreak()

Unfortunately, this didn't have the capacitor we needed.

#align(center, image("media/microwave-closed.jpg", height: 80%))

#pagebreak()

Maybe the makerspace would have some? #pause Nope, we checked.

#pause
Maybe some bins in the underdeck would have some? #pause Nope, we checked.

#pause
Time for plan B.

#pagebreak()

#align(center, image("media/plan-b.jpg", height: 90%))

= Don't Jinx It

== Final Product

#pause
- A fixed Apple \/\/e #pause
- A borked EF ROM #pause
- A useless Super Serial Card (dodgy clone from '84) #pause
- A broken BASIC game #pause
- A program that reads from the cassette at 2 charaters a second #pause
- Over six hundred lines of messy C89 #pause
- A broken power supply #pause
- A microwave main board #pause
- The memories we made along the way

= Trickle-Down Dragonslayer
