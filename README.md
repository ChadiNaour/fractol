# fractol
Fractol is a graphic program that render amazing fractals ,developed for my learning course at 42 school for the exploration of Fractals.

* Zoom and unzoom
* Change the number of iterations
* Move the current fractal
* Change the display color and gradient
* Navigate between the fractals
* Edit the shape of the fractal with the position of the mouse (only available with the fractal Julia,feigenbaum-point ,burning_julia)

## Install & launch
```bash
git clone https://github.com/ChadiNaour/fractol ~/fractol
cd ~/fractol && ./fractol mandelbrot
```
You have to launch the program with a parameter. This is the name of the fractal you would like to open at the execution of the program. This parameter as to be the name of a valid fractal (Julia, Mandelbrot, Burning-julia, Feigenbaum, Teardrop or Tricorn).<br />

## Keyboard shortcuts

<table width="100%">
<thead>
<tr>
<td width="65%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Key(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<tr>
<td valign="top" height="30px">Close the program</td>
<td valign="top" align="center"><kbd>&nbsp;esc&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Change the map</td>
<td valign="top" align="center"><kbd>&nbsp;c&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the up</td>
<td valign="top" align="center"><kbd>&nbsp;▲&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the down</td>
<td valign="top" align="center"><kbd>&nbsp;▼&nbsp;</kbd></td>
</tr>

<tr>
<td valign="top" height="30px">Move the fractal to the left</td>
<td valign="top" align="center"><kbd>&nbsp;◄&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Move the fractal to the right</td>
<td valign="top" align="center"><kbd>&nbsp;►&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Increase the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;+&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Decrease the number of iterations</td>
<td valign="top" align="center"><kbd>&nbsp;-&nbsp;</kbd></td>
</tr>
<tr>
  <td valign="top" height="30px">coloration methode changing</td>
<td valign="top" align="center"><kbd>&nbsp;m&nbsp;</kdb></td>
</tr>
<td valign="top" height="30px">Color changing</td>
<td valign="top" align="center"><kbd>&nbsp;space&nbsp;</kdb></td>
</tr>
<tr>
<td valign="top" height="30px">Freez Julia</td>
<td valign="top" align="center"><kbd>&nbsp;j&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Freez Feingenbaum-point</td>
<td valign="top" align="center"><kbd>&nbsp;f&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Freez Burning-julia</td>
<td valign="top" align="center"><kbd>&nbsp;b&nbsp;</kbd></td>
</tr>
</tbody>
</table>

## Mouse controls

<table width="100%">
<thead>
<tr>
<td width="60%" height="60px" align="center" cellpadding="0">
<strong>Description</strong>
</td>
<td width="10%" align="center" cellpadding="0">
<span style="width:70px">&nbsp;</span><strong>Control(s)</strong><span style="width:50px">&nbsp;</span>
</td>
</tr>
</thead>
<tbody>
<td valign="top" height="30px">Zoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll up&nbsp;</kbd></td>
</tr>
<tr>
<td valign="top" height="30px">Unzoom</td>
<td valign="top" align="center"><kbd>&nbsp;scroll down&nbsp;</kbd></td>
</tr>
</tbody>
</table>

Example :
# Mandelbrot:
<img width="870" alt="Capture d’écran 2022-06-13 à 19 59 56" src="https://user-images.githubusercontent.com/52707617/173425564-8e1d203e-85f8-46c4-865e-f3843c3b73f6.png">

# Julia:
<img width="1000" alt="Screen Shot 2021-02-07 at 4 06 50 PM" src="https://user-images.githubusercontent.com/52707617/107150548-9904c100-695e-11eb-9a42-96eccd5d8c68.png">
<img width="1004" alt="Screen Shot 2021-02-07 at 3 45 26 PM" src="https://user-images.githubusercontent.com/52707617/107150269-48409880-695d-11eb-86d1-26640dc38f31.png">

# Teardrop:
<img width="1004" alt="Screen Shot 2021-02-07 at 3 49 50 PM" src="https://user-images.githubusercontent.com/52707617/107150271-4a0a5c00-695d-11eb-81c1-7ef2a6c7419b.png">

# Feigenbaum-point :
<img width="1005" alt="Screen Shot 2021-02-07 at 3 50 50 PM" src="https://user-images.githubusercontent.com/52707617/107150274-4b3b8900-695d-11eb-9994-37354b34ea57.png">

# Burning-julia:
<img width="1002" alt="Screen Shot 2021-02-07 at 3 51 50 PM" src="https://user-images.githubusercontent.com/52707617/107150275-4d054c80-695d-11eb-8e94-9bf3679a23aa.png">
