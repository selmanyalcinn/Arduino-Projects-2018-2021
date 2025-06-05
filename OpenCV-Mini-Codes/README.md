# OpenCV Mini Codes

This folder contains small projects I created using OpenCV to test motion detection and other computer vision features.  
Specifically, it includes:

## 1️⃣ motionDetector.py
- **What it does:**  
  - Captures frames from the webcam and uses frame differencing to detect motion.  
  - When motion is detected, it saves images (`resim0.jpg`, `resim1.jpg`, …).  
  - The motion detection threshold is set with `esik_deger`.  
  - Motion detection results are displayed in a window.

- **Usage:**  
  - Run the script with Python.  
  - Press `ESC` to exit the program.

- **Notes:**  
  - The code contains many repeated `cv2.imread` calls for reading saved images.  
  - Using Python lists and loops would make this part more efficient.

## 2️⃣ miniProject.py
- Another small script to explore motion detection or related OpenCV features.  
- Serves as a mini testbed for experimentation and learning.

---

## 🗂️ Folder Contents
- **motionDetector.py**: Main motion detection code.  
- **miniProject.py**: Secondary mini project for further exploration.  

---

## 💡 Additional Notes
- These scripts are primarily for testing and learning purposes.  
- For more robust applications, consider using Python lists to load images instead of manually writing many `cv2.imread` lines.  
- You could also explore real-time image visualization using `cv2.imshow` in a loop for slideshows!

---

🎯 **Enjoy exploring motion detection and computer vision with OpenCV!**
