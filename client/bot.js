const TelegramApi = require('node-telegram-bot-api');
const token = '5912527962:AAGnNSbN7dEiT7KBI3lm2Vh4eBNwABYdNEE';

const bot = new TelegramApi(token, {polling: true});
const staticChatID = "";

bot.on('message', msg => {
  const text = msg.text;
  const chatID = msg.chat.id;
  bot.sendMessage(chatID, "hello from bot");
  console.log(msg);
})