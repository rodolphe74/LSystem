# L-System

| First Header  | Second Header |
| ------------- | ------------- |
| Content Cell  | Content Cell  |
| Content Cell  | Content Cell  |

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

<img src="samples/Bush.png" width="200"  alt="bush"/>
