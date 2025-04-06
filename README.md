# L-System
## Bush

  ```C++
// Bush creation
LSystem lsys;
lsys.setAxiom("Y");
lsys.addRule('X', "X[-FFF][+FFF]FX");
lsys.addRule('Y', "YFX[+Y][-Y]");
lsys.recurse(6);
lsys.dumpRecursion();
lsys.setLength(4.0f);
lsys.setAngle((float)DEGTORAD(25.7));
```

```C++
// Displaying using wxWidgets
void MyFrame::OnPaint(wxPaintEvent &event) {
  wxPaintDC dc(this);
  wxGraphicsContext *gc = wxGraphicsContext::Create(dc);
  
  if (gc)
  {
    gc->SetAntialiasMode(wxANTIALIAS_DEFAULT);
    gc->SetPen(wxPen(wxColor(0, 0, 0), 1));
    lsys.wxDraw(gc, 350, 550, (float)M_PI / 2.0f);
    delete gc;
  }
}
```

<td><img src="samples/Bush.png" width="200"  alt="bush"/></td>

## Koch

```C++
lsys.setAxiom("F++F++F");
lsys.addRule('F', "F-F++F-F");
lsys.addRule('Y', "YFX[+Y][-Y]");
lsys.recurse(5);
lsys.dumpRecursion();
lsys.setLength(2.0f);
lsys.setAngle((float)DEGTORAD(60));
```

<td><img src="samples/Koch.png" width="200"  alt="koch"/></td>


## Saupe

```C++
lsys.setAxiom("VZFFF");
lsys.addRule('V', "[+++W][---W]YV");
lsys.addRule('W', "+X[-W]Z");
lsys.addRule('X', "-W[+X]Z");
lsys.addRule('Y', "YZ");
lsys.addRule('Z', " [-FFF][+FFF]F");
lsys.recurse(11);
lsys.dumpRecursion();
lsys.setLength(10.0f);
lsys.setAngle((float)DEGTORAD(20));
```

<td><img src="samples/Saupe.png" width="200"  alt="saupe"/></td>
