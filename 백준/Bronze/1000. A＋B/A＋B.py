# made by kimhs feat.ChatGPT

'''
import random
import json
import math

# 활성화 함수와 그 미분 함수 정의
def relu(x):
    return max(0, x)

def relu_derivative(x):
    return 1 if x > 0 else 0

# 손실 함수 정의
def mean_squared_error(y_true, y_pred):
    return sum((yt - yp) ** 2 for yt, yp in zip(y_true, y_pred)) / len(y_true)

# 레이어 클래스 정의
class Layer:
    def __init__(self, input_size, output_size):
        limit = 1 / math.sqrt(input_size)
        self.weights = [[random.uniform(-limit, limit) for _ in range(input_size)] for _ in range(output_size)]
        self.biases = [random.uniform(-limit, limit) for _ in range(output_size)]
        self.input = None
        self.output = None

    def forward(self, input_data):
        self.input = input_data
        self.output = [relu(sum(i * w for i, w in zip(input_data, weights)) + b)
                       for weights, b in zip(self.weights, self.biases)]
        return self.output

    def backward(self, output_error, learning_rate):
        input_error = [0] * len(self.input)
        for i in range(len(self.weights)):
            for j in range(len(self.input)):
                input_error[j] += output_error[i] * self.weights[i][j] * relu_derivative(self.output[i])
                self.weights[i][j] -= learning_rate * output_error[i] * self.input[j] * relu_derivative(self.output[i])
            self.biases[i] -= learning_rate * output_error[i] * relu_derivative(self.output[i])
        return input_error

    def to_dict(self):
        return {
            'weights': self.weights,
            'biases': self.biases
        }

    @classmethod
    def from_dict(cls, data):
        layer = cls.__new__(cls)
        layer.weights = data['weights']
        layer.biases = data['biases']
        return layer

# 모델 클래스 정의
class Model:
    def __init__(self):
        self.layers = [
            Layer(2, 10),  # 입력 레이어에서 첫 번째 은닉 레이어로
            Layer(10, 5),  # 첫 번째 은닉 레이어에서 두 번째 은닉 레이어로
            Layer(5, 3),   # 두 번째 은닉 레이어에서 세 번째 은닉 레이어로
            Layer(3, 1)    # 세 번째 은닉 레이어에서 출력 레이어로
        ]

    def predict(self, input_data):
        output = input_data
        for layer in self.layers:
            output = layer.forward(output)
        return [round(output[0])]

    def train(self, x_train, y_train, x_val, y_val, epochs, learning_rate):
        for epoch in range(epochs):
            epoch_loss = 0
            for x, y in zip(x_train, y_train):
                # Forward pass
                output = self.predict(x)
                # Calculate error (mean squared error)
                error = [output[0] - y]
                epoch_loss += error[0] ** 2
                # Backward pass
                for layer in reversed(self.layers):
                    error = layer.backward(error, learning_rate)
            epoch_loss /= len(x_train)

            if epoch % 10 == 0:
                # Calculate validation accuracy
                correct_predictions = 0
                for x, y in zip(x_val, y_val):
                    prediction = self.predict(x)[0]
                    if prediction == y:
                        correct_predictions += 1
                validation_accuracy = correct_predictions / len(x_val)

                # Print loss and validation accuracy for the epoch
                print(f'Epoch {epoch + 1}, Loss: {epoch_loss:.4f}, Validation Accuracy: {validation_accuracy:.4f}')

    def save_model(self, filename):
        model_dict = {
            'layers': [layer.to_dict() for layer in self.layers]
        }
        with open(filename, 'w') as f:
            json.dump(model_dict, f)

    def load_from_dict(self, model_dict):
        self.layers = [Layer.from_dict(layer_dict) for layer_dict in model_dict['layers']]

    @classmethod
    def load_model(cls, filename):
        with open(filename, 'r') as f:
            model_dict = json.load(f)
        model = cls()
        model.load_from_dict(model_dict)
        return model

# 데이터 생성
x_train = [[random.randint(1, 9), random.randint(1, 9)] for _ in range(4000)]
y_train = [sum(x) for x in x_train]
x_val = [[random.randint(1, 9), random.randint(1, 9)] for _ in range(1000)]
y_val = [sum(x) for x in x_val]

# 모델 초기화 및 학습
model = Model()
model.train(x_train, y_train, x_val, y_val, epochs=100, learning_rate=0.001)

# 모델 저장
model.save_model('simple_model.json')

# 모델 로드 및 예측 테스트
loaded_model = Model.load_model('simple_model.json')
test_input = [3, 5]
print(f'Prediction for input {test_input}: {loaded_model.predict(test_input)[0]}')
'''

# 활성화 함수 정의
def relu(x):
    return max(0, x)


# 행렬 곱셈 함수 정의
def matmul(weights, inputs):
    return [sum(i * w for i, w in zip(input_row, inputs)) for input_row in weights]


# 행렬 덧셈 함수 정의
def add_biases(outputs, biases):
    return [output + bias for output, bias in zip(outputs, biases)]


# 하드코딩된 모델 파라미터
weights_1 = [[-0.5523202502861667, 0.1404827880519387], [0.5338076464851591, -0.18461329889912959],
             [0.05584727169047082, -0.08524172000027422], [-0.21554093576930117, -0.2742262953988396],
             [-0.08736538032325103, -0.4181081395970499], [-0.28940913983519934, 0.24227454643482788],
             [0.8637185112308351, 0.7757965814750271], [-0.3991180935608831, 0.7589765894069188],
             [-0.20647064859946163, -0.6223487821237925], [-0.0017674008682277975, -0.6264577240985721]]
biases_1 = [0.06285785644004452, 0.46771619777191126, 0.24571037495380146, 0.23374940849368364, -0.11507912688179645,
            -0.6896130570426182, 0.46031051894454983, 0.3840094156555288, -0.21918444854555136, 0.12779869271239475]

weights_2 = [[-0.3014109561832524, -0.3058656080177808, 0.20497615649373674, -0.24406002420040382, -0.1434399688432279,
              -0.3001184683288849, -0.12265312246313045, -0.05575341724912364, 0.2825544873034667, 0.1745009335212101],
             [0.2896187693524895, 0.37298916863783904, -0.022144823433647983, 0.12148876901118627, 0.10735667004632538,
              -0.22968029927630335, 0.666338483747569, 0.2532255403301154, 0.2069193951131048, -0.1598102402199519],
             [0.2709813946380493, -0.0661532113545525, 0.1337685757302114, 0.06287944070235152, 0.2657306912459702,
              -0.22570491192430184, -0.014061725906178296, -0.28065358559937337, -0.10491115044307853,
              0.2936961450733954],
             [0.17441619566465555, 0.2637575890149942, -0.22817363211432598, -0.09484236090844558, -0.2732502115183406,
              -0.16290303774351372, -0.05225647032345048, -0.2011618510220229, 0.07601333238494734,
              -0.13804363013379856],
             [-0.08349812494378651, -0.14746500538295762, -0.2360508432680768, -0.23320399883723195, 0.2370232700349008,
              -0.1654604392927214, 0.6872734930862718, -0.0046950323584881715, -0.14934982883988537, -0.21629009561515]]
biases_2 = [-0.1011986875777664, -0.11067773049632831, 0.1775998385275232, 0.14515725264783694, -0.020434095118123715]

weights_3 = [[-0.42455667901613225, 0.0668429780515038, 0.07620832074898223, 0.3223843005324241, -0.06148394889140395],
             [-0.34546169383552355, 0.7080719980189258, 0.07642738547913572, -0.2587538057530601, 0.6083752833023465],
             [0.31143983320713037, 0.3224994414920896, -0.2054062809173346, 0.41663284615070373, 0.27484259284410933]]
biases_3 = [-0.25567434364300534, 0.29664723834251977, 0.0030143792109865535]

weights_4 = [[-0.37332976560340575, 1.0490247744195933, 0.2942299647283329]]
biases_4 = [-0.1986982663181958]


# 예측 함수 정의
def predict(A, B):
    input_data = [A, B]

    # 첫 번째 레이어
    outputs_1 = matmul(weights_1, input_data)
    outputs_1 = add_biases(outputs_1, biases_1)
    outputs_1 = [relu(x) for x in outputs_1]

    # 두 번째 레이어
    outputs_2 = matmul(weights_2, outputs_1)
    outputs_2 = add_biases(outputs_2, biases_2)
    outputs_2 = [relu(x) for x in outputs_2]

    # 세 번째 레이어
    outputs_3 = matmul(weights_3, outputs_2)
    outputs_3 = add_biases(outputs_3, biases_3)
    outputs_3 = [relu(x) for x in outputs_3]

    # 네 번째 레이어
    outputs_4 = matmul(weights_4, outputs_3)
    outputs_4 = add_biases(outputs_4, biases_4)
    outputs_4 = [relu(x) for x in outputs_4]

    # 최종 출력값 반올림하여 정수로 반환
    return round(outputs_4[0])


# 입력 받기
def main():
    # 사용자 입력 받기
    A, B = map(int, input().split())

    # 모델을 사용하여 예측
    result = predict(A, B)

    # 결과 출력
    print(result)


if __name__ == '__main__':
    main()
