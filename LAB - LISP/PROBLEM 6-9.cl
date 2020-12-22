; Problem 6
(defun DOT-PRODUCT (a b)
  (if (or (null a) (null b))
      0
      (+ (* (first a) (first b))
         (DOT-PRODUCT (rest a) (rest b)))))

; Problem 7
(defun COUNT-NUMBER (list &optional (n 'no-number))
  (cond ((null list) n)
        ((numberp (first list))
         (COUNT-NUMBER (rest list)
                        (if (eq n 'no-number)
                            1
                          (1+ n))))
        (t (COUNT-NUMBER (rest list) n))))

; Problem 8
(defun new-lit (size)
  (make-list size :initial-element T))

; Problem 9
(defun ALL-LENGTH (exp &optional (if-null 1))
  (cond ((null exp) if-null)
        ((atom exp) 1)
        (t (+ (ALL-LENGTH (first exp) 1)
              (ALL-LENGTH (rest exp) 0)))))
