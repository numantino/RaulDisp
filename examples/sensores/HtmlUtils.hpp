#pragma once
#include <Arduino.h>

inline String htmlHeader(String titulo, String extraHead = "")
{
  String html = R"rawliteral(
<!DOCTYPE html><html lang="es">
<head>
  <meta charset="UTF-8">
)rawliteral";

  html += extraHead; // Aquí metemos refresh dinámico

  html += R"rawliteral(
  <style>
    body { font-family: Arial; background:#111; color:#fff; text-align:center; }
    h1 { margin-bottom: 10px; }
    .container { display:flex; justify-content:center; align-items:center; margin-top:30px; }
    .col { width:40%; }
    .separator { width:2px; height:120px; background:#444; margin:0 20px; }
    .value {
      font-size: clamp(1.2rem, 4vw, 2rem);
      font-weight: bold;
    }
    .title {
      font-size: clamp(0.9rem, 2.5vw, 1.2rem);
    }
    .temp { color:#ff4c29; }
    .hum { color:#4cd3ff; }
    .soil { color:#4cd3ff; }
    .status-ok { color:#4cff4c; }
    .status-bad { color:#ff4c29; }

    /* Tarjetas para sensores */
    .grid { 
      display: flex; 
      flex-wrap: wrap; 
      gap: 30px; 
      justify-content: center;
      margin-top: 30px;
    }

    .card { 
      background: #222; 
      border-radius: 10px; 
      padding: 20px;
      box-shadow: 0 2px 6px rgba(0,0,0,0.4); 
      width: 320px;   /* antes 260px */
    }

  </style>
</head>
<body>
)rawliteral";

  html += "<h1>" + titulo + "</h1>";
  return html;
}

inline String htmlFooter()
{
  return "</body></html>";
}
