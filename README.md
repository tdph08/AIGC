# AI Camera Module – Smart Safety System  
*(Fire, Smoke & Violence Detection)*

## 📌 Module Overview
This repository contains the **AI Camera module** developed as part of the project:

**AI–IoT Integrated System for Smart Safety and Greenhouse Gas Monitoring**

This module focuses exclusively on the **AI Edge component**, where cameras act as **real-time intelligent sensors** to enhance safety and early warning capabilities in smart environments such as:

- Smart homes  
- Dormitories  
- Schools  
- Industrial facilities  

The AI module runs on an **edge device (laptop)** and provides detection results with a response time of **under 1 second**.

---

## 👤 Contributor
**Thai Dieu Phuong**  
- Class: 12A6  
- School: Le Quy Don High School – Ha Dong  
- Email: tdp76844@gmail.com  

**Role:**  
AI Engineer – Computer Vision (Camera AI Module)

---

## 🎯 Responsibilities in the Project
This repository covers the parts implemented by **Thai Dieu Phuong**, including:

- Fire & smoke detection using YOLO  
- Real-time object detection from webcam / video streams  
- Dataset research and preprocessing  
- Model testing and deployment on edge devices  
- Integration-ready AI output for cloud/dashboard systems  

> ⚠️ IoT hardware, ESP32 sensors, CO₂e calculation, and cloud dashboards are **outside the scope of this repository**.

---

## 🧠 AI Features Implemented
- 🔥 **Fire Detection**
- 💨 **Smoke Detection**
- ⚠️ Designed to be extendable to:
  - Violence / fighting detection  
  - Face recognition  

---

## 🧰 Technologies Used
- **Python**
- **OpenCV**
- **Ultralytics YOLO (YOLOv8 / YOLOv11)**
- **Google Colab**
- **GitHub**

---

## 📂 Dataset
Fire & Smoke Detection Dataset (Roboflow):  
🔗 https://universe.roboflow.com/hallmark/fire-smoke-qpywc/dataset/1

---

## ⚙️ Environment Setup
```bash
pip install ultralytics opencv-python
```

---

## ▶️ Real-Time Detection (Webcam)
```python
import cv2
from ultralytics import YOLO

model = YOLO("model.pt")  # yolov8n.pt / yolov11n.pt
CONFIDENCE_THRESHOLD = 0.4

cap = cv2.VideoCapture(0)

while True:
    ret, frame = cap.read()
    if not ret:
        break

    results = model(frame, conf=CONFIDENCE_THRESHOLD)[0]
    annotated_frame = results.plot()

    cv2.imshow("AI Camera – Fire & Smoke Detection", annotated_frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
```

---

## 🧩 Integration with the Full AI–IoT System
The AI Camera module provides:
- Detection labels (fire, smoke, confidence scores)
- Bounding box coordinates
- Event triggers for early warning

These outputs are designed to be:
- Sent to a **cloud platform**
- Displayed on a **web or mobile dashboard**
- Combined with IoT sensor data in the full system

---

## 📌 References
- Ultralytics YOLO:  
  https://github.com/ultralytics/ultralytics  

- AI JAM 2023 TOPVN:  
  https://github.com/HocJ2me/AI-JAM-2023-TOPVN  

---

## 🚀 Future Development
- Improve detection accuracy and robustness  
- Optimize inference speed on edge devices  
- Support IP cameras (RTSP stream)  
- Add violence behavior detection  
- Connect to cloud-based alert systems  

---

## 📄 License
This module is developed for **educational, research, and STEM competition purposes**.
