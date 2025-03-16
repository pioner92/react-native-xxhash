# 🚀 react-native-config-jsi

**Fast JSI-based React Native library to access `.env` variables natively with C++ performance.**

---

## 📦 Install

```sh
npm install react-native-config-jsi # or yarn add react-native-config-jsi
```

---

## 🔧 Quick Setup

1. Create `.env` at project root:
```env
API_KEY=your_api_key
APP_NAME=MyAwesomeApp
```

2. **iOS:**
```bash
cd ios && pod install
```
Add to Xcode → Target → Build Phases → **+ New Run Script Phase**:
```bash
bash "${SRCROOT}/../node_modules/react-native-config-jsi/src/scripts/generate.sh"
```

3. **Android:**
Add to bottom of `android/app/build.gradle`:
```gradle
apply from: project(':react-native-config-jsi').projectDir.getPath() + "/dotenv.gradle"
```

---

## 🚀 Usage

```js
import { RNConfig } from "react-native-config-jsi";

const apiKey = RNConfig.get("API_KEY");
console.log("API_KEY:", apiKey);
```

---

## ⚡ Highlights

- 🔥 Ultra-fast JSI native access
- ⚙️ Built in C++
- 🧩 Synchronous API
- 🪶 No extra dependencies

---

## 📜 License

MIT

---

🎉 **Enjoy using react-native-config-jsi!** 🚀
