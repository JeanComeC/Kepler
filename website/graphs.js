import data from './data.json' with { type: 'json' };  // lecture du fichier json

//console.log(data);


// constante des energies
const energyData = data.flatMap(d => [  
  { t: d.t, energie: d.ke, type: "cinétique" },
  { t: d.t, energie: d.pe, type: "potentielle" },
  { t: d.t, energie: d.ke + d.pe, type: "totale" }
]);

const graphEnergies = Plot.plot({  // creation du graph de l'energie
  title: "Énergies",
  x: { label: "t (s)" },
  y: { label: "Énergie (J)" },
  marks: [
    Plot.line(energyData, { x: "t", y: "energie", stroke: "type" }) // on uttilise plot pour tracer les ligne 
  ]
});

document.getElementById("energies").append(graphEnergies); // on l'ajout au div dans l'index 

const graphTrajectoire = Plot.plot({  // creation du graph de la trajectoir sans l'animation 
  title: "Trajectoire de la Terre",
  x: { label: "x (m)" },
  y: { label: "y (m)" },
  marks: [
    Plot.line(data, { x: "x", y: "y" , z: "z"}) // plot pour tracer la trajectoire avec un trait 
  ]
});

document.getElementById("trajectoire").append(graphTrajectoire); // ajout au div dans l'index

// graph de la trajectoire avec l'animation 
let i = 0;
const timer = setInterval(() =>{
  document.getElementById("trajectoire").innerHTML=""; // on vide le div dans l'index 
    let new_data = data.slice(0, i)
    const newGraphTrajectoire =Plot .plot({
      title:"Simulation de la terre",
      x: { label: "x (m)" },
      y: { label: "y (m)" },
      marks : [
    Plot.line(data, { x: "x", y: "y" , z: "z"}),
    Plot.dot([data[i]],{x: "x", y: "y" , z: "z"}), // on cree un point pour la planet avec dot 
]
  })
  document.getElementById("trajectoire").append(newGraphTrajectoire)//injecter dans le div
  i++;
  if(i >= data.length){i = 0};
}, 16) // on reset la position du point tout les 16ms 