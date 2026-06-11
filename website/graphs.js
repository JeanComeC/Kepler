import data from './mercury.json' with { type: 'json' };

//console.log(data);

const energyData = data.flatMap(d => [
  { t: d.t, energie: d.ke, type: "cinétique" },
  { t: d.t, energie: d.pe, type: "potentielle" },
  { t: d.t, energie: d.ke + d.pe, type: "totale" }
]);

const graphEnergies = Plot.plot({
  title: "Énergies de Mercure",
  x: { label: "t (s)" },
  y: { label: "Énergie (J)" },
  marks: [
    Plot.line(energyData, { x: "t", y: "energie", stroke: "type" })
  ]
});

document.getElementById("energies").append(graphEnergies);

const graphTrajectoire = Plot.plot({
  title: "Trajectoire de Mercure",
  x: { label: "x (m)" },
  y: { label: "y (m)" },
  marks: [
    Plot.line(data, { x: "x", y: "y" , z: "z"})
  ]
});

document.getElementById("trajectoire").append(graphTrajectoire);


let i = 0;
const timer = setInterval(() =>{
  document.getElementById("trajectoire").innerHTML="";
    let new_data = data.slice(0, i)
    const newGraphTrajectoire =Plot .plot({
      title:"Animation de la  trajectoire de Mercure ",
      x: { label: "x (m)" },
      y: { label: "y (m)" },
      marks : [
    Plot.line(data, { x: "x", y: "y" , z: "z"}),
    Plot.dot([data[i]],{x: "x", y: "y" , z: "z"}),
]
  })
  document.getElementById("trajectoire").append(newGraphTrajectoire)//injecter dans le div
  i++;
  if(i >= data.length){i = 0};
}, 16)