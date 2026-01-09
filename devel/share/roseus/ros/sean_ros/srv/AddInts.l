;; Auto-generated. Do not edit!


(when (boundp 'sean_ros::AddInts)
  (if (not (find-package "SEAN_ROS"))
    (make-package "SEAN_ROS"))
  (shadow 'AddInts (find-package "SEAN_ROS")))
(unless (find-package "SEAN_ROS::ADDINTS")
  (make-package "SEAN_ROS::ADDINTS"))
(unless (find-package "SEAN_ROS::ADDINTSREQUEST")
  (make-package "SEAN_ROS::ADDINTSREQUEST"))
(unless (find-package "SEAN_ROS::ADDINTSRESPONSE")
  (make-package "SEAN_ROS::ADDINTSRESPONSE"))

(in-package "ROS")





(defclass sean_ros::AddIntsRequest
  :super ros::object
  :slots (_num1 _num2 ))

(defmethod sean_ros::AddIntsRequest
  (:init
   (&key
    ((:num1 __num1) 0)
    ((:num2 __num2) 0)
    )
   (send-super :init)
   (setq _num1 (round __num1))
   (setq _num2 (round __num2))
   self)
  (:num1
   (&optional __num1)
   (if __num1 (setq _num1 __num1)) _num1)
  (:num2
   (&optional __num2)
   (if __num2 (setq _num2 __num2)) _num2)
  (:serialization-length
   ()
   (+
    ;; int32 _num1
    4
    ;; int32 _num2
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _num1
       (write-long _num1 s)
     ;; int32 _num2
       (write-long _num2 s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _num1
     (setq _num1 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; int32 _num2
     (setq _num2 (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass sean_ros::AddIntsResponse
  :super ros::object
  :slots (_sum ))

(defmethod sean_ros::AddIntsResponse
  (:init
   (&key
    ((:sum __sum) 0)
    )
   (send-super :init)
   (setq _sum (round __sum))
   self)
  (:sum
   (&optional __sum)
   (if __sum (setq _sum __sum)) _sum)
  (:serialization-length
   ()
   (+
    ;; int32 _sum
    4
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; int32 _sum
       (write-long _sum s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; int32 _sum
     (setq _sum (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;;
   self)
  )

(defclass sean_ros::AddInts
  :super ros::object
  :slots ())

(setf (get sean_ros::AddInts :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get sean_ros::AddInts :datatype-) "sean_ros/AddInts")
(setf (get sean_ros::AddInts :request) sean_ros::AddIntsRequest)
(setf (get sean_ros::AddInts :response) sean_ros::AddIntsResponse)

(defmethod sean_ros::AddIntsRequest
  (:response () (instance sean_ros::AddIntsResponse :init)))

(setf (get sean_ros::AddIntsRequest :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get sean_ros::AddIntsRequest :datatype-) "sean_ros/AddIntsRequest")
(setf (get sean_ros::AddIntsRequest :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")

(setf (get sean_ros::AddIntsResponse :md5sum-) "4781436a0c2affec8025955a6041e481")
(setf (get sean_ros::AddIntsResponse :datatype-) "sean_ros/AddIntsResponse")
(setf (get sean_ros::AddIntsResponse :definition-)
      "# 客户端请求时发送的两个数字
int32 num1
int32 num2
---
# 服务器响应发送的数据
int32 sum
")



(provide :sean_ros/AddInts "4781436a0c2affec8025955a6041e481")


