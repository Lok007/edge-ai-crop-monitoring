"""
Edge-level image analysis module for crop condition monitoring.
This script demonstrates the structure of an inference pipeline.
"""

import cv2
import numpy as np

def prepare_input(image_path):
    frame = cv2.imread(image_path)
    frame = cv2.resize(frame, (224, 224))
    frame = frame.astype("float32") / 255.0
    return frame

def evaluate_image(frame):
    confidence = np.mean(frame)
    if confidence > 0.55:
        return "Potential Issue Detected"
    else:
        return "Crop Appears Normal"

if __name__ == "__main__":
    input_frame = prepare_input("sample_leaf.jpg")
    output = evaluate_image(input_frame)
    print("Analysis Output:", output)

